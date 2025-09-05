/**
 * @param {Object|Array} obj
 * @return {Object}
 */
var invertObject = function (obj) {
  const ret = Object.create(null);

  for (const [key, value] of Object.entries(obj)) {

    if (Object.prototype.hasOwnProperty.call(ret, value)) {
      // 已存在：若是陣列就 push；若是單值就升級為陣列再放入
      if (Array.isArray(ret[value])) {
        ret[value].push(key);
      } else {
        ret[value] = [ret[value], key];
      }
    } else {
      // 首次出現：先存成單值（若你想一律用陣列，改成 [key] 即可）
      ret[value] = key;
    }
  }
  return ret;
};
