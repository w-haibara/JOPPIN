const express = require("express");
const app = express();

const rl=require("readline").createInterface(process.stdin,process.stdout);

var str = "hello";

(async function(){
    str=await new Promise(res=>rl.once("line",res));
    console.log("Input : " + str);
})();


app.get('/', (req, res) => res.send(str));
app.listen(3000, () => console.log('Listening on port 3000'));
