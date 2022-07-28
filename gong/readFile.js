const fs = require('fs').promises;//fs 모듈  파일 시스템에 접근하여 파일을 생성하거 나 삭제 읽고 쓰기가 가능하다.

fs.writeFile('./readme.txt','글이 입력됩니다.')
    .then(()=>{
        return fs.readFile('./readme.txt');
    })
    
    .then((data)=>{ 
        
        console.log(data.toString());
    })
    .catch((err)=>{
        console.error(err);
    });

