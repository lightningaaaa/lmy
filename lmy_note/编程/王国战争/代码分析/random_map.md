1、报错
twindow::add_linked_widget(const std::string& id, twidget* widget) //window.cpp:1010
    VALIDATE(has_linked_size_group(id), err.str());
    {
        return linked_size_.find(id) != linked_size_.end();
    }