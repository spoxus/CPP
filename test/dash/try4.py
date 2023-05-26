import datetime
import numpy as np
import dash
from dash import dcc, html
import plotly
from dash import Input, Output
import random
random.seed(2)
import math

# pip install pyorbital
#from pyorbital.orbital import Orbital
#satellite = Orbital('TERRA')

#external_stylesheets = ['https://codepen.io/chriddyp/pen/bWLwgP.css']

#app = dash.Dash(__name__, external_stylesheets=external_stylesheets)

app = dash.Dash(__name__)

app.layout = html.Div(
    html.Div([
        html.H4  ('some random data'),
        html.Div (id='live-update-text'),
        dcc.Graph(id='live-update-graph'),
        dcc.Interval(
            id='interval-component',
            interval=30*1000, # in milliseconds
            n_intervals=0
        )
    ])
)


@app.callback(Output('live-update-text', 'children'),
              Input('interval-component', 'n_intervals'))
def update_metrics(n):
    t = datetime.datetime.now()
    x, y = math.cos(random.random()), math.sin(random.random())
    style = {'padding': '5px', 'fontSize': '16px'}
    return [
        html.Span('x: {0:0.2f}'.format(x), style=style),
        html.Span('y: {0:0.2f}'.format(y), style=style)
    ]


# Multiple components can update everytime interval gets fired.
@app.callback(Output('live-update-graph', 'figure'),
              Input('interval-component', 'n_intervals'))
def update_graph_live(n):
    data = {
        'time': [],
        'x': [],
        'y': []
    }

    # Collect some data
    for i in range(5):
        time = datetime.datetime.now() - datetime.timedelta(seconds=i*20)
        increment = 0.5
        x = random.random() + increment
        y = random.randint(0, 10)
        data['x'].append(x)
        data['y'].append(y)
        data['time'].append(time)

    # Create the graph with subplots
    fig = plotly.tools.make_subplots(rows=2, cols=1, vertical_spacing=0.2)
    fig['layout']['margin'] = {
        'l': 30, 'r': 10, 'b': 30, 't': 10
    }
    fig['layout']['legend'] = {'x': 0, 'y': 1, 'xanchor': 'left'}

    fig.append_trace({
        'x': data['x'],
        'y': data['y'],
        'name': 'Altitude',
        'mode': 'lines+markers',
        'type': 'scatter'
    }, 1, 1)
    fig.append_trace({
        'x': data['x'],
        'y': data['y'],
        'text': data['time'],
        'name': 'Longitude vs Latitude',
        'mode': 'lines+markers',
        'type': 'scatter'
    }, 1, 1)

    return fig


if __name__ == '__main__':
    app.run_server(debug=True)

