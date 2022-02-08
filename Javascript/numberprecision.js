const input = "123,45";

// Write an answer using console.log()
// To debug: console.error('Debug messages...');
let check = true; 
let comma = 0;

console.log("Value: "+input);
for(let i = 0; i<input.length; i++) {
    if (input[i] == "-") {
        console.log("Sign: Negative");
        check = false;
        break;
    }
}

for(let i = 0; i<input.length; i++) {
    if (input[i] == ",") {
        comma += 1;
    }
}

if (check == true) {
    console.log("Sign: Positive");
}
if (check == false) {
    console.log("Precision: " + (input.length-comma-1));
}
else {
    console.log("Precision: " + (input.length-comma));
}

console.log("Scale: " + (comma+1))
