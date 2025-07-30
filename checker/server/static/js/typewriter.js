export function typeWriter(text, element, speed = 50) {
	let i = 0;
	element.innerHTML = '';

	return new Promise((resolve) => {
		function type() {
			if (i < text.length) {
				element.innerHTML += text.charAt(i);
				i++;
				setTimeout(type, speed);
			} else {
				resolve();
			}
		}
		type();
	});
}
