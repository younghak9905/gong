const http= require('http');
const fs =require('fs').promises;

http.createServer(async (req, res)=>{
    try{
        const data= await fs.readFile('./server2.html');
        res.writeHead(200, {'Content-Type': 'text.html; charset=utf-8'});//http 상태코드 2xx 성공을 알리는 상태 코드
        res.end(data);
    }catch(err){
        console.error(err);
        res.writeHead(500,{'Content-Type': 'text/plain; charst=utf8'});//상태코드 5xx 서버 오류를 나타냄
        res.end(err.message);
    }
})
.listen(8081, ()=>{
    console.log('8081번 포트에서 서버 대기중입니다.');
});
