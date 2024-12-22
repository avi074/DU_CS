const path = require("path");

// path seperator
console.log(path.sep);

// joining a path
const filePath = path.join("/content", "subfolder", "sample.txt");
console.log(filePath);

// base of a filePath normally last dir/ file
const baseName = path.basename(filePath);
console.log(baseName);

// absolute path
const absolute = path.resolve(__dirname, "content", "subfolder", "sample.txt");
console.log(absolute);
