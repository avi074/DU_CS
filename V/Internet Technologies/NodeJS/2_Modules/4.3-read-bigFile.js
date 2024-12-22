/* Streams --> a sequential io processing used for bigger data to process smoothly & faster

1. Readable   
2. Writeable
3. Duplex
4. Transform

*/

const { createReadStream } = require("fs");

const filePath = __dirname + "/content/big.txt";

// default chunk size = 64kB
// last buffer - remainder
// highWaterMark - control size

const readBig = async (stream /* a read stream object */) => {
    console.log(
        "\nMax readable chunk size : ",
        stream.readableHighWaterMark / 1024,
        " kB"
    );

    stream.on("data", (result) => {
        // result.length is returns chunk size in bytes
        console.log(`\nCurrent Chunk Size : ${result.length / 1024} kB`);
        console.log(result);
    });

    stream.on("error", (err) => {
        console.log(err);
    });
};

// without encoding data will be read in byte stream
// const stream = createReadStream(filePath);
// readBig(stream);

const stream1 = createReadStream(filePath, {
    highWaterMark: 90 * 1024, // in bytes
});
readBig(stream1);
