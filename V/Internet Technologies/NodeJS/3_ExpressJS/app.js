const express = require("express");
const path = require("path");
const logger = require("./logger");
const app = express();

const port = 5077;

// use() is helpful for using static data & functions all over the website
app.use(express.static("./public"));
app.use(logger);

// default response to non-existing requests
app.all(
    "*",
    /* logger,*/ (req, res) => {
        res.status(404).send("<h1>resource not found !!!</h1>");
    }
);

// server listen
app.listen(port, () => {
    console.log(`Server is listening on port ${port} !!!`);
});

/*
// get request

// instead of sending files one by one we can use static folder

app.get("/", (req, res) => {
    // res.status(200).send("Home Page");
    res.sendFile(path.resolve(__dirname, "./basic/index.html"));
});

app.get("/about", (req, res) => {
    res.status(200).send("About Page");
});
*/
