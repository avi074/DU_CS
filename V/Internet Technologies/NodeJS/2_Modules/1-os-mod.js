const os = require("os");

// info about current user
const user = os.userInfo();
console.log("User :", user);

// uptime in seconds of system
console.log(`\nSystem Uptime : ${os.uptime()} seconds`);

// os & hardware details
const currentOS = {
    name: os.type(),
    release: os.release(),
    version: os.version(),
    hostName: os.hostname(),
    cpus: os.cpus(),
    totalMem: os.totalmem(),
    freeMem: os.freemem(),
};
console.log("\nCurrentOS :", currentOS);
