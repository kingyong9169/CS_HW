var logout = () => {
    location.href="index.html";
}

var fruits_list = [
    {
        idf: 1,
        name: 'Apple',
        img_path: 'apple.png',
        price: 5,
        selected: false
    },
    {
        idf : 2,
        name : 'Banana',
        img_path : "banana.png",
        price: 6,
        selected: false
    },
    {
        idf : 3,
        name : 'Orange',
        img_path : "orange.png",
        price: 4,
        selected: false
    },
    {
        idf : 4,
        name : 'Watermelon',
        img_path : "watermelon.jpg",
        price: 6,
        selected: false
    },
    {
        idf : 5,
        name : 'Kiwi',
        img_path : "kiwi.png",
        price: 5,
        selected: false
    },
    {
        idf : 6,
        name : 'strawberry',
        img_path : "strawberry.jpg",
        price: 6,
        selected: false
    },
    {
        idf : 7,
        name : 'Avocado',
        img_path : "avocado.jpg",
        price: 6,
        selected: false
    },
    {
        idf : 8,
        name : 'blueberry',
        img_path : "blueberry.jpg",
        price: 5,
        selected: false
    },
    {
        idf : 9,
        name : 'Cherry',
        img_path : "cherry.jpg",
        price: 6,
        selected: false
    },
    {
        idf : 10,
        name : 'grape',
        img_path : "grape.jpg",
        price: 4,
        selected: false
    },
    {
        idf : 11,
        name : 'lemon',
        img_path : "lemon.jpg",
        price: 3,
        selected: false
    },
    {
        idf : 12,
        name : 'mango',
        img_path : "mango.jpg",
        price: 7,
        selected: false
    },
    {
        idf : 13,
        name : 'peach',
        img_path : "peach.png",
        price: 6,
        selected: false
    },
    {
        idf : 14,
        name : 'pear',
        img_path : "pear.jpg",
        price: 6,
        selected: false
    },
    {
        idf : 15,
        name : 'pineapple',
        img_path : "pineapple.jpg",
        price: 7,
        selected: false
    },
    {
        idf : 16,
        name : 'plum',
        img_path : "plum.jpg",
        price: 7,
        selected: false
    }
];


var table = () => {
    document.write('<table>');
    for (var i = 0; i < fruits_list.length / 4; i++){
        document.write('<tr>');
        for (var j = fruits_list.length / 4 * i; j < fruits_list.length / 4 * (i + 1); j++) {
            document.write('<td class="idf">'+fruits_list[j].idf+'</td>');
        }
        document.write('</tr>');
        document.write("<tr>");
        for (var j = fruits_list.length/4*i; j < fruits_list.length/4*(i+1); j++){
            document.write('<td id="id'+(j)+'"onClick="select('+Number(j)+')">');
            document.write('<img id="'+(j)+ '"style="width:200px; height: 200px" src="image/' + fruits_list[j].img_path + '">');
            document.write('<p>' + fruits_list[j].name + '</p>');
            document.write('<p>' + fruits_list[j].price + '$</p></td>');
        }
        document.write("</tr>");
    }
    document.write('</table>');
}

var alert_name = [];
var alert_price = 0;

var select = (id) => {
    if (fruits_list[id].selected === false) {
        document.getElementById(id).src = 'image/selected.jpg';
        document.getElementById('id' + id).style.backgroundColor = 'red';
        fruits_list[id].selected = true;
        alert_name.splice(id,0,fruits_list[id].name);
        alert_price += fruits_list[id].price;
    }
    else {
        document.getElementById(id).src = 'image/' + fruits_list[id].img_path;
        document.getElementById('id' + id).style.backgroundColor = 'white';
        alert_name.splice(alert_name.indexOf(fruits_list[id].name), 1);
        alert_price -= fruits_list[id].price;
        fruits_list[id].selected = false;
    }
}

var buy = () => {
    if (alert_name.length===0&&alert_price === 0) {
        alert('Please select item!');
    }
    else {
        alert(alert_name + ' is(are) selected!!\n\ntotal : ' + alert_price+'$');
    }
}
