console.log("First");
setTimeout(() => {
    console.log("Second");
}, 1000); // execute once after given time passes
console.log("Third");

setInterval(() => {
    console.log("Interval");
}, 5000); // execute infinite at given time interval in ms

console.log("I am first!!!");

// setTimeout() & setInterval() runs at the end of the code
// because both functions are async
// setTimeout() runs before setInterval()

// that's how we convert setTimeout() to setInterval()
const timeout = async () => {
    for (let i = 0; i < 1000; i++) {
        setTimeout(() => {
            console.log("Hii ", i);
        }, i * 1000);
    }
};
timeout();
