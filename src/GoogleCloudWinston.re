type options;
[@bs.obj]
external options:
    ~level:string=? => ~projectId:string=? => ~keyFilename:string=?
    => unit => options = "";

type constructor;
let newHack: constructor => options => Winston.Transports.t =
    [%bs.raw {|(Constructor, arg) => new Constructor(arg)|}];

[@bs.module "@google-cloud/logging-winston"] external constructor: constructor = "LoggingWinston";
let make = (~level=?, ~projectId=?, ~keyFilename=?, ()) =>
    options(
        ~level=?Belt.Option.map(level, Winston.Types.levelToString),
        ~projectId?, ~keyFilename?, ()
    )
    |> newHack(constructor);