var anagrams = 0;
var str = "cdcd";
var substringOfSameLength = [];
var strArr = [];
for (let i = 0; i < str.length - 1; i++) {
    substringOfSameLength = [];
    for (let j = 0; j < str.length - i; j++) {
        substringOfSameLength.push(str.slice(j, j + i + 1));
    }
    strArr.push(substringOfSameLength);
}

for (let i = 0; i < str.length - 1; i++) {
    for (let j = 0; j < str.length - i; j++) {
        for (let k = j + 1; k < str.length - i; k++) {
            if (wordcheck(strArr[i][j], strArr[i][k])) {
                anagrams++;
            }
        }        
    }    
}

function wordcheck(x, y) {
    for (let i = 0; i < x.length; i++) {
        for (let j = 0; j < y.length; j++) {
            if(x[i] === y[j]) {
                y = y.replace(x[i], "");
            }
        }        
    }
    if (y == "") {
         return true;
    }
    return false;
}
console.log(anagrams);

