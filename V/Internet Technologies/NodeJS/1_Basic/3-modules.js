// Modules - Encapsulated Code (only share minimum)

// CommonJS, every file is module (like python)
const names = require("./4-names");
const sayHi = require("./5-utils");
const data = require("./6-alternative-flavors");
require("./7-mine-grenade");

console.log("names : ", names);
console.log(data);

sayHi("susan");
sayHi(names.john);
sayHi(names.peter);
