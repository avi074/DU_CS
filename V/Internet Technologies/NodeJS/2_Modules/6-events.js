const EventEmitter = require("events");

const customEmitter = new EventEmitter();

customEmitter.on("response", () => {
    console.log("data received");
});

customEmitter.on("response", () => {
    console.log("new data received");
});

// execute all response events that defined before this LOC
customEmitter.emit("response");

// returns nothing as before emiiting there is no events called request
customEmitter.emit("request");

customEmitter.on("request", () => {
    console.log("Request received !!!");
});
