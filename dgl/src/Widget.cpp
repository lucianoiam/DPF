/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2014 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "../Widget.hpp"
#include "../Window.hpp"

START_NAMESPACE_DGL

// -----------------------------------------------------------------------
// Widget

Widget::Widget(Window& parent)
    : fParent(parent),
      fVisible(true)
{
    fParent._addWidget(this);
}

Widget::~Widget()
{
    fParent._removeWidget(this);
}

bool Widget::isVisible() const noexcept
{
    return fVisible;
}

void Widget::setVisible(bool yesNo)
{
    if (fVisible == yesNo)
        return;

    fVisible = yesNo;
    fParent.repaint();
}

void Widget::show()
{
    setVisible(true);
}

void Widget::hide()
{
    setVisible(false);
}

int Widget::getX() const noexcept
{
    return fArea.getX();
}

int Widget::getY() const noexcept
{
    return fArea.getY();
}

const Point<int>& Widget::getPos() const noexcept
{
    return fArea.getPos();
}

void Widget::setX(int x) noexcept
{
    if (fArea.getX() == x)
        return;

    fArea.setX(x);
    fParent.repaint();
}

void Widget::setY(int y) noexcept
{
    if (fArea.getY() == y)
        return;

    fArea.setY(y);
    fParent.repaint();
}

void Widget::setPos(int x, int y) noexcept
{
    setPos(Point<int>(x, y));
}

void Widget::setPos(const Point<int>& pos) noexcept
{
    if (fArea.getPos() == pos)
        return;

    fArea.setPos(pos);
    fParent.repaint();
}

int Widget::getWidth() const noexcept
{
    return fArea.getWidth();
}

int Widget::getHeight() const noexcept
{
    return fArea.getHeight();
}

const Size<int>& Widget::getSize() const noexcept
{
    return fArea.getSize();
}

void Widget::setWidth(int width) noexcept
{
    if (fArea.getWidth() == width)
        return;

    fArea.setWidth(width);
    fParent.repaint();
    onReshape(width, fArea.getHeight());
}

void Widget::setHeight(int height) noexcept
{
    if (fArea.getHeight() == height)
        return;

    fArea.setHeight(height);
    fParent.repaint();
    onReshape(fArea.getWidth(), height);
}

void Widget::setSize(int width, int height) noexcept
{
    setSize(Size<int>(width, height));
}

void Widget::setSize(const Size<int>& size) noexcept
{
    if (fArea.getSize() == size)
        return;

    fArea.setSize(size);
    fParent.repaint();
    onReshape(fArea.getWidth(), fArea.getHeight());
}

uint Widget::getEventTimestamp() const noexcept
{
    return fParent.getEventTimestamp();
}

int Widget::getModifiers() const noexcept
{
    return fParent.getModifiers();
}

App& Widget::getParentApp() const noexcept
{
    return fParent.getApp();
}

Window& Widget::getParentWindow() const noexcept
{
    return fParent;
}

bool Widget::contains(int x, int y) const noexcept
{
    return (x >= 0 && y >= 0 && x < fArea.getWidth() && y < fArea.getHeight());
}

bool Widget::contains(const Point<int>& pos) const noexcept
{
    return contains(pos.getX(), pos.getY());
}

void Widget::repaint() noexcept
{
    fParent.repaint();
}

bool Widget::onKeyboard(bool, uint)
{
    return false;
}

bool Widget::onMouse(int, bool, int, int)
{
    return false;
}

bool Widget::onMotion(int, int)
{
    return false;
}

bool Widget::onScroll(int, int, float, float)
{
    return false;
}

bool Widget::onSpecial(bool, Key)
{
    return false;
}

void Widget::onReshape(int, int)
{
}

// -----------------------------------------------------------------------

END_NAMESPACE_DGL
