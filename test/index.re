let logger = Winston.createLogger(
    ~transports=[| GoogleCloudWinston.make(~keyFilename="sec.json", ()) |],
    ()
);
Winston.info(logger, "howwwwdy");
