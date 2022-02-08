var magazine = "ala vola kha";
var code = "vola Kha";

var magazineWords = magazine.split(" ");
var codeWords = code.split(" ");

var matched = false;
//var matchCount = 0;

for (let i = 0; i < codeWords.length; i++) {
    matched = false;
    for (let j = 0; j < magazineWords.length; j++) {
        if (codeWords[i] == magazineWords[j]) {
            matched = true;
            //matchCount++;
        }
    }
    if (matched == false) {
        console.log("No");
        break;
    }
}

//console.log(matchCount);

if (matched == true) {
    console.log("Yes");
}
