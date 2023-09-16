/**
 * @param {number} millis
 */
async function sleep(millis) {
    const prom = await new Promise((resolve , reject)=>{
        setTimeout(resolve , millis); 
    })
    return prom ; 
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */