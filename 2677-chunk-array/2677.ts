type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function chunk(arr: Obj[], size: number): Obj[][] {
    let result: Obj[][] = [];
    let i = 0;
    while (i < arr.length) {
        if ((arr.length - i) < size) {
            let tmp: Obj[] = [];
            for (; i < arr.length; ++i) {
                tmp.push(arr[i]);
            }
            result.push(tmp);
            break;
        }
        let tmp: Obj[] = [];
        for (let j = 0; j < size; ++j) {
            tmp.push(arr[i++]);
        }
        result.push(tmp);
    }
    return result;
};
