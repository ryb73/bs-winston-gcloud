type options;
[@bs.obj] external options: ~projectId:string=? => ~keyFilename:string=? => unit => options = "";

type constructor;
let newHack: constructor => options => Winston.Transports.t =
    [%bs.raw {|(Constructor, arg) => new Constructor(arg)|}];

[@bs.module "@google-cloud/logging-winston"] external constructor: constructor = "LoggingWinston";
let make = (~projectId=?, ~keyFilename=?, ()) =>
    options(~projectId?, ~keyFilename?, ())
    |> newHack(constructor);