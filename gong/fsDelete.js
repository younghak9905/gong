const fs = require('fs').promises;
fs.readdir('./folder')//폴더 안의 내용물 확인
.then((dir)=>{
    console.log('폴더 내용 확인',dir);
    return fs.unlink('./folder/newfile.js');//파일을 지우는 메서드
})
.then(()=>{
    console.log('파일 삭제 성공');
    return fs.rmdir('./folder');//폴더를 지울 수 있다. 내부 파일 지우고 -> 폴더 지우기

})
.then(()=>{
    console.log('폴더 삭제 성공');
    
})
.catch((err)=>{
    console.error(err);
});
