prevResult= [{
    '@search.score':5,
    'Site_ID' : 1001
},
{
 '@search.score':4,
    'Site_ID' : 1002
},
{
 '@search.score':3,
    'Site_ID' : 1003
}];

let siteIdTositeObjMap_temp = {};
let count = 0;

let skipLessThanScore = 0;
for (let siteObj of prevResult) {

    if (!skipLessThanScore) {
        // if >=1 then reduce by   1, compared to 1st score
        // if  <1 then reduce by 0.1, compared to 1st score
        skipLessThanScore = siteObj["@search.score"];
        if (skipLessThanScore >= 1) {
            skipLessThanScore -= 1;
        } else {
            skipLessThanScore -= 0.1;
        }
    }


    if (
        (skipLessThanScore) &&
        (siteObj["@search.score"] < skipLessThanScore)
    ) {
        continue;
    }

    siteIdTositeObjMap_temp[siteObj.Site_ID] = siteObj;
    count++;
}
