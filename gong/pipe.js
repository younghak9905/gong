const fs= require('fs');

const readStream= fs.createReadStream('readme4.txt');
const WriteStream = fs.createWriteStrean('writeme3.txt');
readStream.pipe(writeStream);//pipe 매서드를 사용하여 writeStream으로 넘어간다.