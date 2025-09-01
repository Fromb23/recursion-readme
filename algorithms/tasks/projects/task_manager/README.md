# Personal Task Management System

## Project Overview
This project implements a comprehensive personal task management system that demonstrates core programming concepts including Object-Oriented Programming (OOP), Functional Programming, System Programming, and File I/O operations. Students will build a command-line application that manages tasks, projects, users, and generates various reports.

## What This Project Tests
- **Object-Oriented Programming**: Classes, inheritance, encapsulation, polymorphism
- **Functional Programming**: Lambda functions, map/filter/reduce, decorators
- **System Programming**: File operations, logging, configuration management
- **Data Structures**: Lists, dictionaries, sets, custom data structures
- **Algorithms**: Sorting, searching, filtering
- **Error Handling**: Custom exceptions, try/catch blocks
- **JSON Processing**: Reading/writing structured data
- **Date/Time Manipulation**: Working with timestamps and scheduling
- **Design Patterns**: Factory, Observer, Strategy patterns

## Prerequisites (What You Need to Know)
- Python basic syntax and data types
- Control flow (if/else, loops)
- Functions and parameter passing
- Basic understanding of classes and objects
- File reading/writing operations
- JSON data format
- Exception handling with try/except
- List comprehensions and basic functional concepts

## Requirements
- **Text Editor**: VSCode (recommended) or any Python-compatible IDE
- **Python Version**: 3.8 or higher
- **Version Control**: Git for tracking changes
- **Libraries**: Only Python standard library (no external dependencies)
- **Operating System**: Cross-platform (Windows, macOS, Linux)

## Project Structure
The project is organized into modular files, each focusing on specific concepts:

---

### 1. Custom Exceptions
Define custom exception classes for the task management system:
- `TaskError`: Base exception for task-related errors
- `TaskNotFoundError`: Raised when task doesn't exist
- `ProjectNotFoundError`: Raised when project doesn't exist
- `UserNotFoundError`: Raised when user doesn't exist
- `InvalidDateError`: Raised for invalid date formats
- `DuplicateTaskError`: Raised when trying to create duplicate task
- `PermissionError`: Raised for unauthorized operations

**File:** `01_exceptions.py`

---

### 2. Date Utilities
Create utility functions for date/time operations:
- Function: `parse_date(date_string):` converts string to datetime object
- Function: `format_date(datetime_obj):` formats datetime to readable string
- Function: `is_past_due(due_date):` checks if date is overdue
- Function: `days_until_due(due_date):` calculates days remaining
- Function: `get_current_timestamp():` returns current timestamp
- Function: `validate_date_format(date_string):` validates date string format
- Function: `add_days_to_date(date, days):` adds specified days to date
- Function: `get_week_range(date):` returns start/end of week for given date

**File:** `02_date_utils.py`

---

### 3. Configuration Manager
Implement a configuration management system:
- Class `ConfigManager` with singleton pattern
- Instance method: `load_config(filename):` loads configuration from JSON
- Instance method: `save_config(filename):` saves current configuration
- Instance method: `get_setting(key, default=None):` retrieves configuration value
- Instance method: `set_setting(key, value):` updates configuration value
- Instance method: `reset_to_defaults():` restores default configuration
- Default settings should include: max_tasks_per_project, default_priority, log_level

**File:** `03_config_manager.py`

---

### 4. Logger System
Create a logging system for the application:
- Class `TaskLogger` for application logging
- Instance method: `log_info(message):` logs informational messages
- Instance method: `log_warning(message):` logs warning messages
- Instance method: `log_error(message, exception=None):` logs error messages
- Instance method: `log_debug(message):` logs debug messages
- Instance method: `set_log_level(level):` configures logging level
- Instance method: `export_logs(filename):` exports logs to file
- Should write logs to both file and console based on configuration

**File:** `04_logger.py`

---

### 5. File Handler
Implement file operations for data persistence:
- Class `FileHandler` for file operations
- Instance method: `read_json(filename):` reads and parses JSON file
- Instance method: `write_json(filename, data):` writes data to JSON file
- Instance method: `backup_file(filename):` creates backup of existing file
- Instance method: `file_exists(filename):` checks if file exists
- Instance method: `create_directory(path):` creates directory if not exists
- Instance method: `get_file_size(filename):` returns file size in bytes
- Instance method: `get_file_modified_time(filename):` returns last modified timestamp
- Should handle file permissions and IO errors gracefully

**File:** `05_file_handler.py`

---

### 6. Priority Enum
Create an enumeration for task priorities:
- Enum `Priority` with values: LOW, MEDIUM, HIGH, CRITICAL
- Each priority should have numeric value (1-4)
- Class method: `from_string(priority_str):` converts string to Priority enum
- Class method: `to_string(priority):` converts Priority enum to string
- Instance method: `compare_priority(other):` compares two priorities
- Should support comparison operations (>, <, ==)

**File:** `06_priority.py`

---

### 7. Task Status Enum
Define task status enumeration:
- Enum `TaskStatus` with values: PENDING, IN_PROGRESS, COMPLETED, CANCELLED
- Instance method: `can_transition_to(new_status):` validates status transitions
- Class method: `get_valid_transitions(current_status):` returns allowed next statuses
- Instance method: `is_active():` returns True if task is active (not completed/cancelled)
- Should include validation for logical status transitions

**File:** `07_task_status.py`

---

### 8. Base Task Class
Implement the core Task class:
- Class `Task` with proper encapsulation
- Private attributes: `_id`, `_title`, `_description`, `_due_date`, `_priority`, `_status`, `_created_at`, `_updated_at`
- Constructor: `def __init__(self, title, description, due_date=None, priority=Priority.MEDIUM):`
- Property methods with getters/setters for all attributes
- Instance method: `update_status(new_status):` changes task status with validation
- Instance method: `is_overdue():` checks if task is past due date
- Instance method: `get_age_days():` returns days since task creation
- Instance method: `to_dict():` converts task to dictionary for JSON serialization
- Class method: `from_dict(data):` creates Task from dictionary
- String representation methods (`__str__`, `__repr__`)

**File:** `08_task.py`

---

### 9. Recurring Task Class
Extend Task class for recurring tasks:
- Class `RecurringTask` inherits from `Task`
- Additional attributes: `_recurrence_pattern`, `_next_due_date`, `_max_occurrences`
- Constructor: `def __init__(self, title, description, recurrence_pattern, max_occurrences=None):`
- Instance method: `generate_next_occurrence():` creates next instance of recurring task
- Instance method: `update_next_due_date():` calculates next due date
- Instance method: `is_recurring_complete():` checks if all occurrences done
- Should support daily, weekly, monthly, yearly recurrence patterns
- Override parent methods as needed for recurring behavior

**File:** `09_recurring_task.py`

---

### 10. User Class
Implement user management:
- Class `User` for system users
- Private attributes: `_user_id`, `_username`, `_email`, `_created_at`, `_preferences`
- Constructor: `def __init__(self, username, email):`
- Instance method: `set_preference(key, value):` updates user preferences
- Instance method: `get_preference(key, default=None):` retrieves user preference
- Instance method: `update_email(new_email):` updates user email with validation
- Instance method: `get_profile_summary():` returns user profile information
- Instance method: `to_dict():` serializes user data
- Class method: `from_dict(data):` deserializes user data
- Email validation and username uniqueness checking

**File:** `10_user.py`

---

### 11. Project Class
Create project container for tasks:
- Class `Project` for organizing tasks
- Private attributes: `_project_id`, `_name`, `_description`, `_owner_id`, `_tasks`, `_created_at`, `_deadline`
- Constructor: `def __init__(self, name, description, owner_id, deadline=None):`
- Instance method: `add_task(task):` adds task to project
- Instance method: `remove_task(task_id):` removes task from project
- Instance method: `get_task(task_id):` retrieves specific task
- Instance method: `get_all_tasks():` returns all project tasks
- Instance method: `get_completion_percentage():` calculates project progress
- Instance method: `get_overdue_tasks():` returns list of overdue tasks
- Instance method: `is_project_complete():` checks if all tasks completed
- Instance method: `get_estimated_completion_date():` estimates completion based on remaining tasks

**File:** `11_project.py`

---

### 12. Task Factory
Implement factory pattern for task creation:
- Class `TaskFactory` for creating different task types
- Class method: `create_simple_task(title, description, due_date=None):` creates basic task
- Class method: `create_recurring_task(title, description, pattern, max_occurrences=None):` creates recurring task
- Class method: `create_urgent_task(title, description, due_date):` creates high-priority task
- Class method: `create_from_template(template_name, **kwargs):` creates task from predefined template
- Class method: `bulk_create_tasks(task_data_list):` creates multiple tasks from list
- Should validate input parameters and return appropriate task objects

**File:** `13_task_factory.py`

---

### 13. Functional Programming Utilities
Create utility functions using functional programming concepts:
- Function: `filter_tasks_by_status(tasks, status):` filters tasks using lambda
- Function: `sort_tasks_by_priority(tasks):` sorts using custom key function
- Function: `map_tasks_to_summaries(tasks):` converts tasks to summary strings
- Function: `reduce_total_estimated_hours(tasks):` calculates total hours using reduce
- Function: `group_tasks_by_project(tasks):` groups tasks using functional approach
- Function: `find_tasks_matching_criteria(tasks, **criteria):` flexible task filtering
- Decorator: `@log_execution_time` for timing function execution
- Decorator: `@validate_task_input` for input validation

**File:** `14_functional_utils.py`

---

### 15. Search and Filter Engine
Implement advanced search capabilities:
- Class `TaskSearchEngine` for searching tasks
- Instance method: `search_by_keyword(keyword):` full-text search in titles/descriptions
- Instance method: `filter_by_date_range(start_date, end_date):` date-based filtering
- Instance method: `filter_by_priority(min_priority):` priority-based filtering
- Instance method: `filter_by_user(user_id):` user-specific tasks
- Instance method: `advanced_search(**criteria):` combines multiple search criteria
- Instance method: `sort_results(results, sort_by='priority'):` sorts search results
- Should support complex queries and return ranked results

**File:** `15_search_engine.py`

---

### 16. Statistics Calculator
Create statistical analysis for tasks and projects:
- Class `TaskStatistics` for generating insights
- Instance method: `calculate_completion_rate(user_id=None):` percentage of completed tasks
- Instance method: `get_average_completion_time():` average time to complete tasks
- Instance method: `get_productivity_trends():` analyzes productivity over time
- Instance method: `get_priority_distribution():` breakdown of tasks by priority
- Instance method: `get_overdue_statistics():` analysis of overdue tasks
- Instance method: `generate_user_report(user_id):` comprehensive user statistics
- Instance method: `compare_project_performance():` compares project metrics
- Should use functional programming concepts for calculations

**File:** `16_statistics.py`

---

### 17. Notification System
Implement notification/reminder system:
- Class `NotificationManager` for handling notifications
- Instance method: `schedule_reminder(task_id, reminder_time):` schedules task reminder
- Instance method: `send_due_date_notifications():` checks and sends due date alerts
- Instance method: `send_overdue_notifications():` handles overdue task notifications
- Instance method: `get_pending_notifications():` returns scheduled notifications
- Instance method: `mark_notification_sent(notification_id):` marks notification as sent
- Instance method: `cancel_notification(notification_id):` cancels scheduled notification
- Should integrate with logger for notification tracking

**File:** `17_notification_system.py`

---

### 18. Data Validation
Create comprehensive validation system:
- Class `DataValidator` for input validation
- Static method: `validate_email(email):` validates email format
- Static method: `validate_task_title(title):` validates task title requirements
- Static method: `validate_date_string(date_str):` validates date format
- Static method: `validate_priority(priority):` validates priority value
- Static method: `validate_project_name(name):` validates project name
- Static method: `sanitize_input(input_str):` cleans user input
- Instance method: `validate_task_data(task_dict):` comprehensive task validation
- Should raise appropriate custom exceptions for validation failures

**File:** `18_data_validator.py`

---

### 19. Import/Export Manager
Handle data import/export operations:
- Class `DataImportExport` for data migration
- Instance method: `export_to_csv(tasks, filename):` exports tasks to CSV format
- Instance method: `import_from_csv(filename):` imports tasks from CSV
- Instance method: `export_project_report(project_id, format='json'):` exports project data
- Instance method: `backup_all_data(backup_dir):` creates complete system backup
- Instance method: `restore_from_backup(backup_file):` restores system from backup
- Instance method: `export_user_data(user_id, filename):` exports specific user data
- Should handle different file formats and data validation during import

**File:** `19_import_export.py`

---

### 20. Cache Manager
Implement caching for performance optimization:
- Class `CacheManager` for storing frequently accessed data
- Instance method: `cache_task(task_id, task_obj):` stores task in cache
- Instance method: `get_cached_task(task_id):` retrieves task from cache
- Instance method: `invalidate_cache(task_id):` removes task from cache
- Instance method: `cache_search_results(query, results):` caches search results
- Instance method: `get_cached_search(query):` retrieves cached search results
- Instance method: `clear_expired_cache():` removes old cache entries
- Instance method: `get_cache_statistics():` returns cache hit/miss statistics
- Should implement LRU (Least Recently Used) cache eviction policy

**File:** `20_cache_manager.py`

---

### 21. Task Scheduler
Implement task scheduling and automation:
- Class `TaskScheduler` for automated task operations
- Instance method: `schedule_task_creation(task_data, schedule_time):` schedules future task creation
- Instance method: `auto_update_recurring_tasks():` processes recurring task updates
- Instance method: `schedule_cleanup_completed_tasks():` schedules cleanup operations
- Instance method: `get_scheduled_operations():` returns pending scheduled operations
- Instance method: `execute_pending_operations():` runs due scheduled operations
- Instance method: `cancel_scheduled_operation(operation_id):` cancels scheduled operation
- Should handle time zones and scheduling conflicts

**File:** `21_task_scheduler.py`

---

### 22. Report Generator
Create comprehensive reporting system:
- Class `ReportGenerator` for generating various reports
- Instance method: `generate_user_productivity_report(user_id):` creates user productivity analysis
- Instance method: `generate_project_status_report(project_id):` creates project overview
- Instance method: `generate_overdue_tasks_report():` lists all overdue tasks
- Instance method: `generate_weekly_summary():` creates weekly activity summary
- Instance method: `generate_priority_analysis():` analyzes task priority distribution
- Instance method: `export_report_to_file(report_data, filename, format='txt'):` saves report to file
- Should support multiple output formats (text, JSON, CSV)

**File:** `22_report_generator.py`

---

### 23. Database Simulator
Implement an in-memory database simulation:
- Class `TaskDatabase` simulating database operations
- Instance method: `create_table(table_name, schema):` creates table structure
- Instance method: `insert_record(table_name, record):` inserts data record
- Instance method: `select_records(table_name, conditions=None):` queries records
- Instance method: `update_record(table_name, record_id, updates):` updates existing record
- Instance method: `delete_record(table_name, record_id):` removes record
- Instance method: `create_index(table_name, field_name):` creates search index
- Instance method: `get_table_statistics(table_name):` returns table metadata
- Should simulate SQL-like operations using Python data structures

**File:** `23_database_simulator.py`

---

### 24. Event System
Implement observer pattern for system events:
- Class `Event` representing system events
- Class `EventManager` for event handling
- Instance method: `subscribe(event_type, callback):` registers event listener
- Instance method: `unsubscribe(event_type, callback):` removes event listener
- Instance method: `emit_event(event_type, event_data):` triggers event
- Instance method: `get_event_history():` returns recent event log
- Events should include: task_created, task_completed, task_overdue, project_completed
- Callbacks should be executed asynchronously where possible

**File:** `24_event_system.py`

---

### 25. Command Parser
Create command-line interface parser:
- Class `CommandParser` for parsing user commands
- Instance method: `parse_command(command_string):` parses user input into action and parameters
- Instance method: `validate_command(command, args):` validates command syntax
- Instance method: `get_help_text(command=None):` returns help information
- Instance method: `autocomplete_command(partial_command):` suggests command completions
- Should support commands like: create, list, update, delete, search, report
- Include command aliases and parameter validation

**File:** `26_command_parser.py`

---

### 26. Task Manager Core
Implement the main task management logic:
- Class `TaskManager` as the central coordinator
- Private attributes: `_tasks`, `_projects`, `_users`, `_database`, `_logger`, `_cache`
- Instance method: `create_task(title, description, **kwargs):` creates new task
- Instance method: `update_task(task_id, **updates):` modifies existing task
- Instance method: `delete_task(task_id):` removes task
- Instance method: `complete_task(task_id):` marks task as completed
- Instance method: `search_tasks(**criteria):` searches tasks using search engine
- Instance method: `get_user_tasks(user_id):` returns tasks for specific user
- Instance method: `assign_task_to_project(task_id, project_id):` links task to project
- Should coordinate between all other system components

**File:** `27_task_manager.py`

---

### 27. Project Manager
Implement project-level operations:
- Class `ProjectManager` for project operations
- Instance method: `create_project(name, description, owner_id, deadline=None):` creates new project
- Instance method: `update_project(project_id, **updates):` modifies project
- Instance method: `delete_project(project_id):` removes project (with validation)
- Instance method: `add_task_to_project(project_id, task_id):` links task to project
- Instance method: `remove_task_from_project(project_id, task_id):` unlinks task
- Instance method: `get_project_timeline(project_id):` returns project schedule
- Instance method: `calculate_project_metrics(project_id):` returns project statistics
- Should handle project dependencies and milestone tracking

**File:** `28_project_manager.py`

---

### 28. User Manager
Implement user management system:
- Class `UserManager` for user operations
- Instance method: `create_user(username, email):` creates new user account
- Instance method: `authenticate_user(username, password):` user login simulation
- Instance method: `update_user_profile(user_id, **updates):` modifies user data
- Instance method: `delete_user(user_id):` removes user (with data cleanup)
- Instance method: `get_user_activity(user_id):` returns user activity summary
- Instance method: `set_user_permissions(user_id, permissions):` manages user access
- Instance method: `get_all_users():` returns list of all users
- Should handle user preferences and permission levels

**File:** `29_user_manager.py`

---

### 29. API Simulator
Create a REST API simulation:
- Class `TaskAPISimulator` simulating web API endpoints
- Instance method: `handle_get_request(endpoint, params=None):` simulates GET requests
- Instance method: `handle_post_request(endpoint, data):` simulates POST requests
- Instance method: `handle_put_request(endpoint, data):` simulates PUT requests
- Instance method: `handle_delete_request(endpoint, params):` simulates DELETE requests
- Instance method: `authenticate_request(headers):` simulates API authentication
- Instance method: `format_response(data, status_code=200):` formats API response
- Should return JSON responses and handle HTTP status codes

**File:** `30_api_simulator.py`

---

### 30. Performance Monitor
Implement system performance monitoring:
- Class `PerformanceMonitor` for tracking system metrics
- Instance method: `start_monitoring():` begins performance tracking
- Instance method: `stop_monitoring():` ends performance tracking
- Instance method: `record_operation(operation_name, duration):` logs operation timing
- Instance method: `get_performance_metrics():` returns performance statistics
- Instance method: `identify_bottlenecks():` analyzes slow operations
- Instance method: `generate_performance_report():` creates performance summary
- Should track memory usage, operation timing, and system resource utilization

**File:** `31_performance_monitor.py`

---

### 31. System Integration
Create the main application class:
- Class `TaskManagementSystem` as the main application controller
- Constructor: `def __init__(self):` initializes all system components
- Instance method: `initialize_system():` sets up database, loads configuration
- Instance method: `run_interactive_mode():` starts command-line interface
- Instance method: `process_command(command):` executes user commands
- Instance method: `shutdown_system():` properly closes system and saves data
- Instance method: `run_automated_maintenance():` performs background tasks
- Instance method: `handle_system_error(error):` manages system-level errors
- Should coordinate all managers and provide unified interface

**File:** `32_system_integration.py`

---

### 32. Main Application
Implement the application entry point:
- Main execution script with proper entry point
- Function: `display_welcome_message():` shows application startup message
- Function: `show_main_menu():` displays available options
- Function: `handle_user_input():` processes user choices
- Function: `run_demo_mode():` demonstrates system capabilities with sample data
- Function: `setup_sample_data():` creates demonstration tasks and projects
- Include command-line argument parsing for different modes (interactive, demo, batch)
- Should handle graceful shutdown and error recovery

**File:** `33_main.py`

---

## Implementation Guidelines

### Programming Paradigms Focus:
1. **Object-Oriented Programming**: Classes should demonstrate proper encapsulation, inheritance, and polymorphism
2. **Functional Programming**: Use higher-order functions, immutable operations where possible, and pure functions
3. **System Programming**: Handle file operations, logging, and system resources properly

### Code Quality Standards:
- Follow PEP 8 style guidelines
- Include comprehensive docstrings for all classes and methods
- Implement proper error handling with custom exceptions
- Use type hints where appropriate
- Write self-documenting code with meaningful variable names

### Testing Your Implementation:
Each file should be testable independently. Create sample data and test edge cases for each component. The final system should handle real-world scenarios like:
- Large numbers of tasks and projects
- Invalid user input
- File corruption or missing files
- System resource limitations
- Concurrent operation simulation

### Integration Requirements:
- All components must work together seamlessly
- Data should persist between application runs
- System should handle errors gracefully without crashing
- Performance should remain acceptable with hundreds of tasks/projects

## Getting Started
1. Create a new directory for your project
2. Initialize a git repository
3. Start implementing files in numerical order
4. Test each component thoroughly before moving to the next
5. Create sample data to test system integration
6. Document any design decisions or challenges encountered

Remember: This project emphasizes practical application of programming concepts rather than just theoretical knowledge. Focus on creating a robust, maintainable system that demonstrates professional programming practices.