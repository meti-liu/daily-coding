
document.getElementById('backButton').addEventListener('click', function() {
    window.location.href = 'hw1.html'; 
});


function A(num) {
    var content = document.getElementById('content');
    
    switch(num) {
        case 1:
            content.innerHTML = 
            `<h2>C-潜袭爬虫</h2>   
            <p>装备一架潜袭爬虫，按【射击】将爬虫抛向前方，直接控制其移动。再次按【射击】可触发脉冲，压制并揭露被击中的敌人。</p>     
            <video width="640" height="480" controls>   <source src="video1.mp4" type="video/mp4">    </video>`;
            break;
        case 2:
            content.innerHTML = 
            `<h2>Q-特快专递</h2>   
            <p>装备一颗粘性榴弹，按【射击】发射。榴弹会粘附击中的首个表面并爆炸，被爆炸波及的所有目标都会受到震荡。按【辅助射击】发射榴弹时，榴弹会在反弹一次后爆炸。</p>     
            <video width="640" height="480" controls>   <source src="video2.mp4" type="video/mp4">    </video>`;
            break;
        case 3:
            content.innerHTML = 
            `<h2>E-精准投放</h2>   
            <p>装备一套战术投送系统。按【射击】在地图上选择最多两个目标位置。按【辅助射击】发射导弹。导弹可自动导航至目标位置，然后引爆。</p>     
            <video width="640" height="480" controls>   <source src="video3.mp4" type="video/mp4">    </video>`;
            break;
        case 4:
            content.innerHTML = 
            `<h2>X-末日审判</h2>   
            <p>装备战术打击地图。按【射击】选择打击起点，【再次按射击键】设置终点并发动无人机空袭，沿所选路径进行地毯式爆破。在地图瞄准期间按【辅助射击】可取消起点设置。</p>     
            <video width="640" height="480" controls>   <source src="video4.mp4" type="video/mp4">    </video>`;
            break;
        default:
            content.innerHTML = '<h2>请选择一个板块</h2><p>点击上方的板块来查看不同的内容。</p>';
    }
}
