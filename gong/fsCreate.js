const fs = require('fs').promises;
const constants = require('fs').constants;

fs.access('./folder', constants.F_OK | constants.W_OK | constants.R_OK)//폴더나 파일에 접근할 수 있는지 체크
  .then(() => {
    return Promise.reject('이미 폴더 있음');
  })
  .catch((err) => {
    if (err.code === 'ENOENT') {
      console.log('폴더 없음');
      return fs.mkdir('./folder');//폴더 만드는 메서드
    }
    return Promise.reject(err);
  })
  .then(() => {
    console.log('폴더 만들기 성공');
    return fs.open('./folder/file.js', 'w');//파일의 아이디(fd변수)를 가져오는 메서드
  })
  .then((fd) => {
    console.log('빈 파일 만들기 성공', fd);
    fs.rename('./folder/file.js', './folder/newfile.js');//파일의 이름을 바꾸는 메서드
  })
  .then(() => {
    console.log('이름 바꾸기 성공');
  })
  .catch((err) => {
    console.error(err);
  });