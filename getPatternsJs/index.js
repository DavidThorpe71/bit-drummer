const fs = require('fs')

const getBin = (myNumber) => myNumber.toString(2);

const numToByteArray = function(num) {
    // we want to represent the input as a 8-bytes array
    var byteArray = [0, 0, 0, 0, 0, 0, 0, 0];

    for ( var index = 0; index < byteArray.length; index ++ ) {
        var byte = num & 0xff;
        byteArray [ index ] = byte;
        num = (num - byte) / 256 ;
    }

    return byteArray;
};

const patternArray = [];

const main = () => {
    for (let i = 0; i < 256; i++) {
        let binArr = getBin(i)
        // console.log(binArr);
        if (binArr[binArr.length - 1] == "1") {
            
            patternArray.push(i);
        }
    }
    console.log(patternArray);

    patternArray.sort((a, b) => {
        let a1count = getBin(a).split("").filter(x => x==="1").length;
        let b1count = getBin(b).split("").filter(x => x==="1").length;

        if (a1count < b1count) {
            return -1
        }
        return 1;
    })
    fs.writeFile('test.json', JSON.stringify(patternArray), err => {
        if (err) {
          console.error(err)
          return
        }
        //file written successfully
      })

}


main();