const fs = require('fs');

setInterval(()=>{
    fs.unlink('./abvdefg.js',(err)=>{
        if(err){
            console.log(err);

        }
    });
},1000);