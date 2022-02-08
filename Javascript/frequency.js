var query = [[1,1], [2,2], [3,2], [1,1], [1,1], [2,1], [3,2]];
var arr = [];
for (let i = 0; i < query.length; i++) {
	if (query[i][0] == 1) {
		arr.push(query[i][1]);
	}
	else if (query[i][0] == 2) {
		for (let j = 0; j < arr.length; j++) {
			if (query[i][1] == arr[j]) {
				arr.splice(j,1);
			}
		}
	}
	else if (query[i][0] == 3) {
		var out = 0;
		var checked = false;
		var checklist = [];
		var occurance = 0;
		for (let j = 0; j < arr.length; j++) {

			checked = false;

			for (let k = 0; k < checklist.length; k++) {
				if (checklist[k] == arr[j]) {
					checked = true;
				}
			}

			if (!checked) {
				checklist.push(arr[j]);
				for (let k = 0; k < arr.length; k++) {
					if (arr[j] == arr[k]) {
						occurance++
					}					
				}
			}
			console.log(occurance)
			if (occurance == query[i][1]) {
				out = 1;
				console.log(out);
				break;
			}		
		}

		if (out == 0) {
			console.log(out);
		}

	}
}
