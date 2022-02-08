var str1 = "before";
var str2 = "hl";
var check = false;
for (let i = 0; i < str1.length; i++) {
    for (let j = 0; j < str2.length; j++) {
        if (str1[i] == str2[j]) {
            console.log("Yes");
            check = true;
        }        
    }    
}

if (!check) {
    console.log("No");
}