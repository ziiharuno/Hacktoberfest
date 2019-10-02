open System

[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"
    printfn "What a lovely day %s" (Environment.UserName.ToString())  
    0
