const http = require('http');
const fs = require('fs').promises;
const url = require('url');
const qs = require('querystring');

const parseCookies = (cookie = '') =>//parseCookie 문자열을 객체로 변환
  cookie
    .split(';')
    .map(v => v.split('='))
    .reduce((acc, [k, v]) => {
      acc[k.trim()] = decodeURIComponent(v);
      return acc;
    }, {});
http.createServer(async (req, res) => {
  const cookies = parseCookies(req.headers.cookie);
  // 주소가 /login으로 시작하는 경우
  if (req.url.startsWith('/login')) {
    const { query } = url.parse(req.url);
    const { name } = qs.parse(query);
    const expires = new Date();
    // 쿠키 유효 시간을 현재시간 + 5분으로 설정
    expires.setMinutes(expires.getMinutes() + 5);
    res.writeHead(302, {
      Location: '/',
      'Set-Cookie': `name=${encodeURIComponent(name)}; Expires=${expires.toGMTString()}; HttpOnly; Path=/`,
    });//쿠키에는 줄바꿈과 한글이 들어가서는 안된다.  쿠키는 옵션 사이에 ; 을 써서 구분한다.
        //name = 쿠기 값: 기본적 쿠키 값 Expires=날짜 만료 기한 , 이 기한이 지나면 쿠키 제거
        //domain = 도메인 쿠키가 전송될 도메인을 특정 Path=URL 쿠키가 전송될 url을 특정 Secure https 일 경우에만 쿠키 전송
        //HttpOnly 설정시 자바 스크립트에서 쿠키에 접근할 수 없다.
        res.end();//name이라는 쿠키가 있는 경우
    } else if (cookies.name) {
        res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
        res.end(`${cookies.name}님 안녕하세요`);
      } else {
        try {
          const data = await fs.readFile('./cookie2.html');
          res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
          res.end(data);
        } catch (err) {
          res.writeHead(500, { 'Content-Type': 'text/plain; charset=utf-8' });
          res.end(err.message);
        }
      }
    })
      .listen(8084, () => {
        console.log('8084번 포트에서 서버 대기 중입니다!');
      });