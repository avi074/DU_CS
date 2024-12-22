const fs = require("fs");

const fileName = __dirname + "/content/subfolder/sample.txt";

fs.readFile(fileName, "utf-8", (err, result) => {
    if (err) {
        console.log(err);
        return;
    }
    console.log(result);
    fs.writeFile(fileName, `File Location is : ${fileName}`, (err, result) => {
        if (err) {
            console.log(err);
            return;
        }
        console.log(result);
    });
});
