# human_detect

Скачать пакет opencv_apps можно по ссылке https://github.com/ros-perception/opencv_apps, затем распаковать его в workspace.
Пакет human_detect также распаковать в workspace и запустить human_detect.launch

Изображение берется из топика /ardrone/front/image_raw

Результат обработки выводится в топик /humanDetected в виде std_msgs::Bool, в котором data = true, если человек обнаружен и false, если нет.
