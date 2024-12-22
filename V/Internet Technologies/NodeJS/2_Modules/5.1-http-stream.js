const fs = require("fs");
const http = require("http");

const port = 5077;

const server = http.createServer();

// request events

/* when we send big data at once through response then it will 
   affect the loading speed as well as productivity of server
   so instead of sending/reading/writing all data at once
   we should use streams as it's a better optimistic approach 

server.on("request", (req, res) => {
    const text = fs.readFileSync(__dirname + "/content/big.txt", "utf-8");
    res.end(text);
});
*/

server.on("request", (req, res) => {
    const textStream = fs.createReadStream(
        __dirname + "/content/big.txt",
        "utf-8"
    );

    textStream.on("open", () => {
        textStream.pipe(res); // pipeline approach
    });
    textStream.on("error", (err) => {
        res.end(err);
    });
});

// error event
server.on("error", (err) => {
    console.log(err);
});

server.listen(port, () => {
    console.log(`Server listening at ${port} port number !!!`);
});
