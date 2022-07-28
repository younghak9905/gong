const fs = require('fs');

const readStrean = fs.createReadStream('./readme3.txt',{highWaterMark: 16});
const data= [];

readStrean.on('data',(chunk)=>{
    data.push(chunk);
console.log('data: ', chunk,chunk.length);
});

readSrteam.on('end',()=>{
    console.log('end :',Buffer.concat(data).toString());

});
fs.ReadStream.on('error',(err)=>{
    console.log('error',err);
});