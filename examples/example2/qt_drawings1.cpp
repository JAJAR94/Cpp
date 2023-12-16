#include <QApplication>

#include <QPainter>
#include <QWidget>

struct Point {
    int x;
    int y;
};

void drawPoints(QPainter& qp)
{
    static constexpr Point points[] = {
        {10, 15}, {20, 30}, {50, 10}
    };

    qp.setPen(Qt::NoPen);
    qp.setBrush(QColor("#FF0000"));
    for (const auto& pt: points) {
        qp.drawEllipse(pt.x - 5, pt.y -5, 10, 10);
    }
}

class DrawingsWindow: public QWidget {
public:
    explicit DrawingsWindow(QWidget* parent = 0);
protected:
    void paintEvent(QPaintEvent* e) override;
};

void DrawingsWindow::paintEvent(QPaintEvent* e)
{
    QPainter qp(this);
    qp.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    qp.setBrush(Qt::white);
    qp.drawRect(10, 10, 200, 200);

    drawPoints(qp);
}

DrawingsWindow::DrawingsWindow(QWidget* parent)
: QWidget(parent) {}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    DrawingsWindow window;
    window.setFixedSize(640, 480);
    window.setWindowTitle("Drawings 1");
    window.show();
    return app.exec();
}
