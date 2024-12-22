const http = require("http");

// using Event Emitter API
const server = http.createServer();

// emitting request event on server
server.on("request", (req, res) => {
    res.end("Welcome");
});

server.listen(5000);
