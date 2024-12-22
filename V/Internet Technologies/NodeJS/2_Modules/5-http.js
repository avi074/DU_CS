const http = require("http");

const port = 5177;

const server = http.createServer((req, res) => {
    switch (req.url) {
        case "/":
            res.end("Welcome to Node Server !!!");
            break;

        case "/about":
            res.end("About Page !!!");
            break;

        case "/contact":
            for (let i = 0; i < 1000; i++) {
                res.write(`${i}\t`);
            }
            res.end("Contact via pHp !!!");
            break;

        default:
            res.end("Error 404  !!!");
    }
});

server.listen(port, () => {
    console.log(`Server listening at ${port} port !!!`);
});
