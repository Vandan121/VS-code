// const url = 'https://jsonmock.hackerrank.com/api/asteroids';

// async function getResponse() {
// //   let response = await fetch(url);
// //   response = await response.json();
// //   console.log(response)
//   const total_pages = response.total_pages;
// //   console(total_pages)
//   const discovery = "2010";
//   const orbit_class = "aten";
//   let data = [];
//   for(let i = 1; i <= total_pages; ++i) {
//     let response = await fetch(url + `?page=${i}`);
//     response = await response.json();
//     // console.log(response);
//     for(let idx = 0; idx < response.data.length; ++idx) {
//       if(response.data[idx].orbit_class.toLowerCase() == orbit_class && response.data[idx].discovery_date.substring(0,4) == discovery) {
//         data.push(response.data[idx]);
//       }
//     }
//   }
// //   console.log(data);
//   data = data.sort((a,b) => {
//     if(!a.period_yr) a.period_yr = 1;
//     if(!b.period_yr) b.period_yr = 1;
//     if(a.period_yr == b.period_yr) {
//         return b.designation - a.designation;
//     }
//     return b.period_yr - a.period_yr;
//   });
//   let ret = [];
//   for(let i = 0; i < data.length; ++i) {
//     ret.push(data[i].designation)
//   }
// //   console.log(ret.reverse())
// }

// getResponse();




let request = new XMLHttpRequest();
let url = "http://jsonmock.hackerrank.com/api/asteroids/search?page="+1;
request.open("GET", url, false);
request.send();
let r = JSON.parse(request.responseText);
let total_pages = r["total_pages"];
let list=[];
for (let i = 1; i <= total_pages; i++) {
    let req = new XMLHttpRequest();
    let url = "http://jsonmock.hackerrank.com/api/asteroids/search?page="+i;
    req.open("GET", url, false);
    req.send();
    let data = JSON.parse(req.responseText);
    for (let j of data["data"]) {
        if (year === j["discovery_date"].slice(0, 4) && j["orbit_class"].toLowerCase().includes(orbit_class.toLowerCase())) {
            if (j["period_yr"] === null) {
                j["period_yr"] = 1;
            }
            j["period_yr"] = parseFloat(j["period_yr"]);
            list.push(j);
        }
    }
}
list.sort((a, b) => a["period_yr"] - b["period_yr"] || a["designation"].localeCompare(b["designation"]));
let desg = [];
for (let j of list) {
    desg.push(j["designation"]);
}
