// const fs = require("fs");
// fs.readFileSync()

const { readFileSync, writeFileSync } = require("fs");

// fileName / filePath
const fileName = __dirname + "/content/subfolder/sample.txt";

// in sync process use flag instead of flags
const write = writeFileSync(fileName, `\nThe fileName is ${fileName}`, {
    flag: "a",
});

const read = readFileSync(fileName, "utf-8");

console.log(read);
