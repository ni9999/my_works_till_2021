var triplets = 0;
var arr = [1,3,9,9,27,81];
var r = 3;

for (let i = 0; i < arr.length - 2; i++) {
    for (let j = i+1; j < arr.length - 1; j++) {
        for (let k = i+2; k < arr.length; k++) {
			if (arr[k] / arr[j] == r && arr[j] / arr[i] == r) {
                triplets++;
            }
        }       
    }    
}


console.log(triplets);