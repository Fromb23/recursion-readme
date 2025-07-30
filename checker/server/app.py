from flask import Flask, render_template, request, jsonify
import subprocess
import os

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")



@app.route("/validate", methods=["POST"])
def validate():
    if request.is_json:
        data = request.get_json()
        task_name = data.get("task_name")
        repo_url = data.get("repo_url")
    else:
        task_name = request.form.get("task_name")
        repo_url = request.form.get("repo_url")

    if not task_name or not repo_url:
        return "Task name and repo URL are required", 400

    try:
        result = subprocess.run(
                ["./checker", "--task-name", task_name, "--repo", repo_url],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                cwd="../",
                timeout=30
                )
    except subprocess.TimeoutExpired:
        return "Checker timed out", 500
    except FileNotFoundError:
        return "Checker executable not found", 500

    # If it's an HTML form, render response.html
    if not request.is_json:
        return render_template(
                "response.html",
                task_name=task_name,
                repo_url=repo_url,
                stdout=result.stdout,
                stderr=result.stderr,
                exit_code=result.returncode
                )

    # Otherwise return JSON
    semantic_error = "Validation failed" in result.stderr or "Missing" in result.stderr or "not found" in result.stderr
    return {
            "task_name": task_name,
            "repo_url": repo_url,
            "exit_code": 1 if semantic_error or result.returncode != 0 else 0,
            "stdout": result.stdout,
            "stderr": result.stderr
            }


@app.route('/health', methods=['GET'])
def health_check():
    return jsonify({"status": "ok", "message": "Checker is running"}), 200


if __name__ == "__main__":
    app.run(debug=True)
