const EventEmitter = require('events');
//on: 이벤트 이름과 이벤트 발생 시의 콜백을 연결한다.
const myEvent = new EventEmitter();
myEvent.addListener('event1',()=>{//addListener on과 기능이 같다.
    console.log('이벤트 1');
});
myEvent.on('event2',()=>{
    console.log('이벤트 2');
});
myEvent.on('event2',()=>{
    console.log('이벤트 2 추가');
});
myEvent.once('event3',()=>{// once 한 번만 실행되는 이벤트
    console.log('이벤트 3');
});

myEvent.emit('event1');//emit: 이벤트를 호출하는 메서드
myEvent.emit('event2');
myEvent.emit('event3');
myEvent.emit('event3');

myEvent.on('event4',()=>{
    console.log('이벤트 4');
});
myEvent.removeAllListeners('event4');//이벤트에 연결된 모든 이벤트 리스너를 제거
myEvent.emit('event4');

const listener=()=>{
    console.log('이벤트 5');
};
myEvent.on('event5',listener);
myEvent.removeListener('event5',listener);//이벤트에 연결된 리스너를 하나씩 제거// off(이벤트 명, 리스너) 같은기능
myEvent.emit('event5');

console.log(myEvent.listenerCount('event2'));//현재 리스너가 몇개 연결되어 있는지 확인