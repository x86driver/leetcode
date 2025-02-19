interface String {
    replicate(times: number): string;
}

String.prototype.replicate = function(times): string {
    let output = "";
    for (let i = 0; i < times; ++i) {
        output += this;
    }
    return output;
}
