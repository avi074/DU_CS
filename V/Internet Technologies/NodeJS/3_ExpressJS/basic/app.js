const http = require("http");
const fs = require("fs");

// In nodejs we have to createmultiple responses for every html,css,js & other type file
// It's a little lengthy process & so we use express as a better approach

const port = 5077;

// get all files
const homePage = fs.readFileSync("./index.html");
const homeStyle = fs.readFileSync("./style.css");
const errorPage = fs.readFileSync("./error.html");

const server = http.createServer((req, res) => {
    // status code is code of your response
    // content-type is MIME type like what you are sending as response
    const url = req.url;
    switch (url) {
        case "/":
            res.writeHead(200, { "content-type": "text/html" });
            res.write(homePage);
            break;

        case "/style.css":
            res.writeHead(200, { "content-type": "text/css" });
            res.write(homeStyle);
            break;

        case "/error.html":
            res.writeHead(204, { "content-type": "text/html" });
            res.write(errorPage);

        default:
            break;
    }
    console.log(req.method);
    console.log(url);
    res.end();
});

server.listen(port);
