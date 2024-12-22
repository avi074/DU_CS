const { readFile, writeFile } = require("fs").promises;

const fileName = __dirname + "/content/subfolder/sample.txt";

const start = async () => {
    try {
        const data = await readFile(fileName, "utf-8");
        await writeFile(fileName, `This is Awesome : ${data}`, { flags: "a" });
        console.log(data);
    } catch (error) {
        console.log(error);
    }
};

start();
