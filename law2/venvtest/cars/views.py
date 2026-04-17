from django.shortcuts import redirect, render
from cars.models import Car
from law2.venvtest import cars
from cars.forms import CarModelForm
from django.shortcuts import redirect, render
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth import authenticate, login, logout

# Create your views here.

def cars_view(request):

    search = request.GET.get('search')
    if search:
        cars = Car.objects.filter(model__contains=search).order_by('model')
    else:
        cars = Car.objects.all().order_by('model')
    """
    filtro na chave estrangeira
    cars = Car.objects.filter(brand=1)
    cars = Car.objects.filter(brand__name='Fiat')
    cars = Car.objects.filter(model__contains='o')
    icontains- ignora uppercase e lowercase
    order_by se colocar o- na frente do campo, faz decrescente
    """
    return render(request, 'cars.html', {'cars': cars})

def new_car_view(request):
    if request.method == 'POST':
        new_car_form = CarModelForm(request.POST, request.FILES)
    if new_car_form.is_valid():
        new_car_form.save()
        return redirect('cars_list')
    else:
        #new_car_form = CarForm()
        new_car_form = CarModelForm()
    return render(request, 'new_car.html',
                  {'new_car_form': new_car_form})

def register_view(request):
    if request.method == 'POST':
        user_form = UserCreationForm(request.POST)
        if user_form.is_valid():
            user_form.save()
            return redirect('login')
    else:
        user_form = UserCreationForm()
    return render(request, 'register.html', {'user_form': user_form})

def login_view(request):
    if request.method == 'POST':
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            return redirect('cars_list')
        else:
            login_form = AuthenticationForm()
    else:
        login_form = AuthenticationForm()
    return render(request, 'login.html', {'login_form': login_form})

def logout_view(request):
    logout(request)
    return redirect('cars_list')