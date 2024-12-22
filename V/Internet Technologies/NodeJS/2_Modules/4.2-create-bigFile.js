const { writeFileSync } = require("fs");

const filePath = __dirname + "/content/big.txt";

try {
    for (let i = 0; i <= 10000; i++) {
        writeFileSync(filePath, `Hello World ${i} times \n`, {
            flag: "a",
        });
    }
    console.log("Writing Done 👍️!!!");
} catch (error) {
    console.log(error);
}
