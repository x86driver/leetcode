/**
 * @param {number} times
 * @return {string}
 */
String.prototype.replicate = function(times) {
    let output = "";
    for (let i = 0; i < times; i++) {
        output += this;
    }
    return output;
}
