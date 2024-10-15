// function main(region, keyword) {
//     let list = {};
//     let response = new XMLHttpRequest();
//     let url = 'https://jsonmock.hackerrank.com/api/countries/search?region=' + region;
//     response.open('GET', url, false);
//     response.send();
//     let data = response.responseText;
//     console(data)
//     let result = JSON.parse(data);
//     for (let i = 0; i < parseInt(result['total_pages']); i++) {
//         let response = new XMLHttpRequest();
//         let url = 'https://jsonmock.hackerrank.com/api/countries/search?region=' + region + '&page=' + (i+1);
//         response.open('GET', url, false);
//         response.send();
//         let data = response.responseText;
//         let json_data = JSON.parse(data);
//         for (let j of json_data['data']) {
//             if (j['name'].toLowerCase().includes(keyword.toLowerCase())) {
//                 list[j['name']] = j['population'];
//             }
//         }
//     }
//     let sorted_list = Object.entries(list).sort((a, b) => a[1] - b[1] || a[0].localeCompare(b[0]));
//     for (let [i, j] of sorted_list) {
//         console.log(i + ',' + j);
//     }
// }
// if (require.main === module) {
//     main("Asia", "in");
// }

let url = 'https://jsonmock.hackerrank.com/api/countries/search'

async function main(region, keyword) {
    let response = await fetch(url);
    response = await response.json();
    // console.log(response)
    const total_pages = response.total_pages;
    // console.log(total_pages)
    let data = []
    for(let i=0;i<total_pages;i++){
        response = await fetch(url + `?page=${i}`);
        response = await response.json();
        // console.log(response)
        for(let idx = 0;idx < response.data.length;idx++){
            if(response.data[idx].region == region){
                // data.push(response.data[idx]);
                data.push({name: response.data[idx].name, population: response.data[idx].population});
            }
        }
    }

    data.sort( (a, b) =>{
        if(a.population == b.population) {
            return b.name - a.name;
        } else {
            return a.population - b.population;
        }
    } )
    let ans = [];
    for(let i=0;i<data.length;i++) {
        ans.push(`${data[i].name}, ${data[i].population}` );
    }
    console.log(ans)



}
if (require.main === module) {
    main("Asia", "in");
}
