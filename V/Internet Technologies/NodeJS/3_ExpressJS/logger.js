// middleware function
// req => middleware => res

const logger = (req, res, next) => {
    const log = {
        method: req.method,
        url: req.url,
        time: new Date().toLocaleString(),
    };
    console.log(log);
    next();
};

module.exports = logger;
