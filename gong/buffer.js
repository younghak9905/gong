const buffer = Buffer.from('저를 버퍼로 바꿔보세요');
console.log('from():',buffer); //from 문자열을 버퍼로 바꾼다.
console.log('length:',buffer.length); 
console.log('toString():',buffer.toString());//toString 버퍼를 다시 문자열로 바꿀 수 있다.

const array=[Buffer.from('띄엄'),Buffer.from('띄엄'), Buffer.from('띄어쓰기')];
const buffer2 = Buffer.concat(array); //concat 배열 안에 든 버퍼들을 하나로 합친다.
console.log('concat():',buffer2.toString());

const buffer3 = Buffer.alloc(5); //alloc 빈버퍼를 생성
console.log('alloc():', buffer3);