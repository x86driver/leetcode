type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | JSONValue[]

function isEmpty(obj: Obj): boolean {
    let count = 0;
    for (let [key, value] of Object.entries(obj)) {
        ++count;
    }
    return count === 0;
};
